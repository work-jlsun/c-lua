/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief: lua 脚本中调用 宿主机(c语言)中 代码 
 */
 
#include <lua.h>       //Lua语言解析器
#include <lualib.h>    //Lua标准库
#include <lauxlib.h>   //Lua辅助工具

/**
 * Lua调用的宿主函数具有统一的原型:int f(lua_State *s)
 * 数据传递不通过其参数，而是通过堆栈；整型返回值指明
 * 了该函数真正向lua返回的值的个数，即压栈的结果个数。
 * 函数返回后，Lua虚拟机会自动清理栈工作，不许在函数内
 * 部来做。
 */ 



 //供Lua使用的函数通用原型
int divide(lua_State *s) {
    double a = lua_tonumber(s, -2); //取得第一个参数   
    double b = lua_tonumber(s, -1); //取得第二个参数
    int quot = (int)a /(int)b;      
    int rem = (int)a %(int) b;      
    lua_pushnumber(s, quot);        //将第一个返回值入堆栈
    lua_pushnumber(s, rem);         //将第二个返回值入堆栈
    return 2;                       //返回值为结果的个数
}

int main(int argc, char *argv[]) {
    lua_State *s = luaL_newstate();  //新建lua虚拟机
    luaL_openlibs(s);               //打开lua附加库
    lua_register(s,"div", divide);
    luaL_dofile(s,"demo2.lua");
    lua_close(s);                   //关闭虚拟机
    return 0;

}
