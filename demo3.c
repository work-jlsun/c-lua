/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief:  
 */
 
#include <lua.h>       //Lua语言解析器
#include <lualib.h>    //Lua标准库
#include <lauxlib.h>   //Lua辅助工具


int main() {
    lua_State *s = luaL_newstate();
    luaL_openlibs(s);
    luaL_dofile(s,"demo3.lua");

    lua_getglobal(s,"show");            
    lua_pushstring(s, "It is from C");
    lua_call(s, 1,1);

    const char *result = lua_tostring(s, -1); //取到栈顶的返回值
    printf("C has got:%s\n",result);
    lua_pop(s, 1);

    lua_close(s);
    return 0;
}

/**
 * 可见, 宿主语言可以通过名称方便得取得Lua的全局变量(lua_getglobal),
 * 而Lua中显然把函数也当成了一种数据。这一特性，可以使Lua源代码成为
 * 功能最强的配置文件，这也是项目中最容易引入Lua的方式
 */


