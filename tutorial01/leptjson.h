#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, 
               LEPT_NUMBER, LEPT_STRING, 
                LEPT_ARRAY, LEPT_OBJECT } lept_type; //JSON数据类型

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,      //无错误返回值
    LEPT_PARSE_EXPECT_VALUE,    //JSON只含有空白
    LEPT_PARSE_INVALID_VALUE,   //不是JSON语法子集 ABNF规定的三种字面值
    LEPT_PARSE_ROOT_NOT_SINGULAR    //一个值后，在空白之后还有其他字符
};

int lept_parse(lept_value* v, const char* json); 
//解析JSON，传入的JSON是一个C字符串，这个字符串不能够改动，使用const char*类型

lept_type lept_get_type(const lept_value* v); //访问结果，获取其类型

#endif /* LEPTJSON_H__ */
