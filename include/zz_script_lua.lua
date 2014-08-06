-------------------------------------------------------------------------------------------
--- ��ƿ� �������̽� ��� �ڵ� �����ϴ� ��ũ��Ʈ
--- �Է����� : zz_interface.h
--- ������� : zz_script_lua.inc
---
--- ������ : $(SolutionDir)..\..\lua401\bin\lua.exe $(SolutionDir)..\..\include\zz_script_lua.lua
---
--- $Header: /engine/include/zz_script_lua.lua 3     04-02-29 10:31p Zho $
---
--- 2003-11-30 zho
---   zz_api_define.inc �� zz_api_register.inc �� zz_script_lua.inc �� ��ħ.
---   ���� �̸��� export_interface.lua ���� zz_script_lua.lua �� ����.
--- 
--- 2003-11-29 zho
---   converted to perfect cpp format not to confuse parameter evaluation ordering.
---
--- 2004-02-28 zho
---  converted to lua500
-------------------------------------------------------------------------------------------

IN_FILENAME  = "zz_interface.h"
OUT_FILENAME = "zz_script_lua.inc"

interfaces = {} -- �������̽� ���� ���̺�

names = {} --- ���Ŀ� �̸� ���̺�

--- ��ũ�� ���� ���̺��
map_return_types = {
    void    = "RETURNS_NONE",
    int     = "RETURNS_INT",
    float   = "RETURNS_FLOAT",
    HNODE   = "RETURNS_HNODE",
    ZSTRING = "RETURNS_STRING"
}
map_param_types = {
    void    = "",
    int     = "ZL_INT",
    float   = "ZL_FLOAT",
    HNODE   = "ZL_HNODE",
    ZSTRING = "ZL_STRING"
}

section1 = "//--------------------------------------------------------------------------------\n"..
"// %s\n"..
"//--------------------------------------------------------------------------------\n"..
"int zz_lua_%s (lua_State * L)\n"..
"{\n"..
"\tint param_index = 1;\n"..
"\tconst char where[] = \"%s\";\n"..
"\tint return_num = 0;\n"..
"\n"

section2 = {
	void = "\t// no parameter\n",
	int = "\tint %s = get_param_int( L, param_index, where );\n",
	float = "\tfloat %s = get_param_float( L, param_index, where );\n",
	HNODE = "\tHNODE %s = get_param_uint( L, param_index, where );\n",
	ZSTRING = "\tZSTRING %s = get_param_string( L, param_index, where );\n"
}	

section3 = {
	void = "\t%s( ", -- no return value
	int = "\n\tset_param_int( L, return_num, %s( ",
	float = "\n\tset_param_float( L, return_num, %s( ",
	HNODE = "\n\tset_param_uint( L, return_num, %s( ",
	ZSTRING = "\n\tset_param_string( L, return_num, %s( ",
}

section4 = {
	void = " ", -- no parameter
	int = "%s%s ",
	float = "%s%s ",
	HNODE = "%s%s ",
	ZSTRING = "%s%s ",
}	

section5 = {
	void = " );\n\n\treturn return_num;\n}\n\n",
	int = ") );\n\n\treturn return_num;\n}\n\n",
	float = ") );\n\n\treturn return_num;\n}\n\n",
	HNODE = ") );\n\n\treturn return_num;\n}\n\n",
	ZSTRING = ") );\n\n\treturn return_num;\n}\n\n",
}

--- ��� �޼���
message_autogen =
"//--------------------------------------------------------------------------------\n"..
"// �� ������ zz_script_lua.lua ��ũ��Ʈ�� ���� �ڵ������� �ڵ��Դϴ�.\n"..
"//\n"..
"// ���� �������� ���ʽÿ�.\n"..
"// �����ð�: "..os.date().."\n"..
"//--------------------------------------------------------------------------------\n\n"

--- ������ �� ǥ��
message_end_of_file = "// end of file.\n"

--------------------------------------------------------------------------------------
-- is_whitespace
--------------------------------------------------------------------------------------
function is_whitespace ( c )
	if (c == nil) then return nil end
	if (c == '\n') then return true end
	if (c == '\t') then return true end
	if (c == ' ') then return true end
	return false
end

--------------------------------------------------------------------------------------
--  skip_whitespace ()
--------------------------------------------------------------------------------------
function skip_whitespace ()
	local c = io.read ( 1 )
	if (c == nil) then return nil end
	
	while ( is_whitespace( c ) ) do
		c = io.read ( 1 )
		if (c == nil) then return nil end
	end
	return c
end

--------------------------------------------------------------------------------------
-- read_word
--------------------------------------------------------------------------------------
prechar = ""
function read_word ()
	local c = skip_whitespace()
	local word = ""
	
	if (c == nil) then return nil end
	
	while ( not is_whitespace( c ) ) do
		word = word .. c
		c = io.read ( 1 )
		if (c == nil) then return nil end
	end
	prechar = c
	return word
end

--------------------------------------------------------------------------------------
--- read_interfaces
--------------------------------------------------------------------------------------
--- ������ �о� interfaces ���̺� ���� ����
function read_interfaces ( )
    i = 1
    word = read_word ()
	
    while ( word ) do
        if (word ~= "ZZ_SCRIPT") then
			if (prechar ~= '\n') then -- if preword is '\n', then already skipped the line.
				word = io.read( "*l" ) -- skip current line
			end
        else
			local return_type
            local name
            return_type = read_word ()
            
            if (not return_type) then break end

            name = read_word ()
            
            if (not name) then break end

            interfaces[name] = {}

            interfaces[name].return_type = return_type

            word = read_word () -- skip (
            if (not word) then break end

            word = read_word ()
            if (not word) then break end

            interfaces[name].params = {}
            local param_index = 1
            
            -- get parameters
            while (word ~= ");") do
                -- extract out comma(,)
                param_type = string.gsub( word, ",", "" )
                word = read_word () 
                if (not word) then break end
                if (word == ");") then break end
                param_name = string.gsub( word, ",", "" )
                interfaces[name].params[param_index] = {}
                interfaces[name].params[param_index]["name"] = param_name
                interfaces[name].params[param_index]["type"] = param_type                
                -- set parameter name
                word = read_word () -- read next
                if (not word) then break end
                param_index = param_index + 1
            end
            i = i + 1
        end -- end of if
        word = read_word () -- read next
    end -- end of while
end

--------------------------------------------------------------------------------------
--- �ʱ�ȭ. �������̽� ������� �а�, ���� ���� ����
--------------------------------------------------------------------------------------
function initialize ()
    --- �������̽� ���� �о���̱�
    h_in   = io.open ( IN_FILENAME   ) -- input file handle
	io.input( h_in )
    read_interfaces ()
    io.close ( h_in )
    
    i = 1
    index = next(interfaces, nil) -- �̸����� �����ϴ� ���̺��̹Ƿ�, interfaces[i] �� ����� �� ����.
    while (index) do
        names[i] = index
        index = next(interfaces, index)
        i = i + 1
    end
    --- �̸������� �����ϱ�
    table.sort( names )
end

--------------------------------------------------------------------------------------
--- ��ũ��Ʈ �������̽� ���� ���
--------------------------------------------------------------------------------------
function write_definition ( )
    io.write ( message_autogen )
    
    for i = 1, table.getn(names) do
        -- section1
        definition = string.format( section1, names[i], names[i], names[i] )
        
        -- section2
        for j = 1, table.getn(interfaces[names[i]].params) do
            definition = definition..string.format(
                section2[ interfaces[ names[i] ].params[j]["type"] ],
                interfaces[ names[i] ].params[j]["name"] )
        end

        -- section3
        definition = definition..string.format( section3[ interfaces[ names[i] ].return_type ], names[i] )
        
        -- section4
        for j = 1, table.getn( interfaces[ names[ i ] ].params ) do
            if ( j == table.getn( interfaces[ names[ i ] ].params ) ) then
                definition = definition..string.format( section4[ interfaces[ names[i] ].params[j]["type"] ], 
                    interfaces[ names[i] ].params[j]["name"], "" )
            else
                definition = definition..string.format( section4[ interfaces[ names[i] ].params[j]["type"] ],
                    interfaces[ names[i] ].params[j]["name"], ","  )
            end
        end

        -- section5
        definition = definition..section5[ interfaces[ names[i] ].return_type ]
            
        io.write ( definition )
    end
end

--------------------------------------------------------------------------------------
--- ��ũ��Ʈ �������̽� ��Ϻκ� ���
--------------------------------------------------------------------------------------
function write_register ( )
	io.write ( "//--------------------------------------------------------------------------------\n// register api interfaces\n"..
		"//--------------------------------------------------------------------------------\n" )
    io.write ( "void register_api_interfaces (lua_State * L)\n{\n" )
    register_section = "\tlua_register( L, \"%s\", zz_lua_%s );\n"
    
    for i = 1, table.getn(names) do
        register = string.format( register_section, names[i], names[i] )
        io.write ( register )
    end
    io.write ( "}\n" )
end

--------------------------------------------------------------------------------------
--- ���� �Լ�
--------------------------------------------------------------------------------------
function main ()
    initialize()
    h_out = io.open ( OUT_FILENAME, "w+" )
    io.output( h_out )
    write_definition ( )
    write_register ()
	io.write ( message_end_of_file )
    io.close ( h_out )
end

main()