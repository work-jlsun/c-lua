/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief: lua �ű��е��� ������(c����)�� ���� 
 */
 
#include <lua.h>       //Lua���Խ�����
#include <lualib.h>    //Lua��׼��
#include <lauxlib.h>   //Lua��������

/**
 * Lua���õ�������������ͳһ��ԭ��:int f(lua_State *s)
 * ���ݴ��ݲ�ͨ�������������ͨ����ջ�����ͷ���ֵָ��
 * �˸ú���������lua���ص�ֵ�ĸ�������ѹջ�Ľ��������
 * �������غ�Lua��������Զ�����ջ�����������ں�����
 * ��������
 */ 



 //��Luaʹ�õĺ���ͨ��ԭ��
int divide(lua_State *s) {
    double a = lua_tonumber(s, -2); //ȡ�õ�һ������   
    double b = lua_tonumber(s, -1); //ȡ�õڶ�������
    int quot = (int)a /(int)b;      
    int rem = (int)a %(int) b;      
    lua_pushnumber(s, quot);        //����һ������ֵ���ջ
    lua_pushnumber(s, rem);         //���ڶ�������ֵ���ջ
    return 2;                       //����ֵΪ����ĸ���
}

int main(int argc, char *argv[]) {
    lua_State *s = luaL_newstate();  //�½�lua�����
    luaL_openlibs(s);               //��lua���ӿ�
    lua_register(s,"div", divide);
    luaL_dofile(s,"demo2.lua");
    lua_close(s);                   //�ر������
    return 0;

}
