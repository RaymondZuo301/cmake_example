#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "ray/math/core/add.h"
#include "ray/math/core/minus.h"
#include "ray/math/core/multiply.h"
#include "ray/math/core/divide.h"

/* @file Calculator.hpp */

namespace ray {
namespace math {

/**
 * @brief 操作符
 *
 */
enum Operator
{
    ADD = 0,
    MINUS = 1,
    MULTIPLY = 2,
    DIVIDE = 3
};

/** @class Calculator
 *  @brief 计算类
 *  @author Raymond
 *  @date 2020
 */
class Calculator
{
public:
    /**
     * @brief 构造函数
     *
     */
    Calculator();


    /**
     * @brief 重载()operator
     *
     * @param[in] a 操作数1
     * @param[in] b 操作数2
     * @param[in] op 操作符
     * @return 运算结果
     */
    template <typename A, typename B>
    decltype(A()+B()) operator()(const A &a, const B &b, Operator op) const
    {
        switch(op){
        case ADD:
            return Add()(a, b);
        case MINUS:
            return Minus()(a, b);
        case MULTIPLY:
            return Multiply()(a, b);
        case DIVIDE:
            return Divide()(a, b);
        }
    }
};

}}

#endif // CALCULATOR_H
