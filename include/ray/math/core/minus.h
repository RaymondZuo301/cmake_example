#ifndef MINUS_H
#define MINUS_H

/* @file Minus.hpp */

namespace ray {
namespace math {

/** @class Minus
 *  @brief 减法类
 *  @author Raymond
 *  @date 2020
 */
class Minus
{
public:
    /**
     * @brief 构造函数
     *
     */
    Minus();

    /**
     * @brief 重载()operator
     *
     * @param[in] a 操作数1
     * @param[in] b 操作数2
     * @return 运算结果
     */
    template <typename A, typename B>
    decltype(A()-B()) operator()(const A &a, const B &b) const
    {
         return a-b;
    }
};

}}

#endif // MINUS_H
