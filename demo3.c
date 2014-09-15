/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief:  
 */
 
#include <lua.h>       //Lua���Խ�����
#include <lualib.h>    //Lua��׼��
#include <lauxlib.h>   //Lua��������


int main() {
    lua_State *s = luaL_newstate();
    luaL_openlibs(s);
    luaL_dofile(s,"demo3.lua");

    lua_getglobal(s,"show");            
    lua_pushstring(s, "It is from C");
    lua_call(s, 1,1);

    const char *result = lua_tostring(s, -1); //ȡ��ջ���ķ���ֵ
    printf("C has got:%s\n",result);
    lua_pop(s, 1);

    lua_close(s);
    return 0;
}

/**
 * �ɼ�, �������Կ���ͨ�����Ʒ����ȡ��Lua��ȫ�ֱ���(lua_getglobal),
 * ��Lua����Ȼ�Ѻ���Ҳ������һ�����ݡ���һ���ԣ�����ʹLuaԴ�����Ϊ
 * ������ǿ�������ļ�����Ҳ����Ŀ������������Lua�ķ�ʽ
 */


