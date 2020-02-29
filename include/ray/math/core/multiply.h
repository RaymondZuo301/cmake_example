#ifndef MULTIPLY_H
#define MULTIPLY_H

/* @file Multiply.hpp */

namespace ray {
namespace math {

/** @class Multiply
 *  @brief 乘法类
 *  @author Raymond
 *  @date 2020
 */
class Multiply
{
public:
    /**
     * @brief 构造函数
     *
     */
    Multiply();

    /**
     * @brief 重载()operator
     *
     * @param[in] a 操作数1
     * @param[in] b 操作数2
     * @return 运算结果
     */
    template <typename A, typename B>
    decltype(A()*B()) operator()(const A &a, const B &b) const
    {
         return a*b;
    }
};

}}

#endif // MULTIPLY_H
