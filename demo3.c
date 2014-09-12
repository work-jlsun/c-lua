/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief:  
 */
 
#include <lua.h>       //Lua���Խ�����
#include <lualib.h>    //Lua��׼��
#include <lauxlib.h>   //Lua��������



int main() {
    lua_State *s = luaL_newstate();
    luaL_openLibs(s);
    lua_dofile(s,"demo3.lua");

    lua_getglobal(s,"show");            
    lua_pushstring(s, "It is from C");
    lua_call(s, 1,1);
}
