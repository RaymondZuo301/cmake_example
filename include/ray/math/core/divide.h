#ifndef DIVIDE_H
#define DIVIDE_H

/* @file Divide.hpp */

namespace ray {
namespace math {

/** @class Divide
 *  @brief 除法类
 *  @author Raymond
 *  @date 2020
 */
class Divide
{
public:
    /**
     * @brief 构造函数
     *
     */
    Divide();

    /**
     * @brief 重载()operator
     *
     * @param[in] a 操作数1
     * @param[in] b 操作数2
     * @return 运算结果
     */
    template <typename A, typename B>
    decltype(A()/B()) operator()(const A &a, const B &b) const
    {
         return a/b;
    }
};

}}

#endif // DIVIDE_H
