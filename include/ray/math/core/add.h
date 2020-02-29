#ifndef ADD_H
#define ADD_H

/* @file Add.hpp */

/**
 * @brief 主命名空间
 *
 */
namespace ray {
/**
 * @brief 数学库
 *
 */
namespace math {

/** @class Add
 *  @brief 加法类
 *  @author Raymond
 *  @date 2020
 */
class Add
{
public:
    /**
     * @brief 构造函数
     *
     */
    Add();

    /**
     * @brief 重载()operator
     *
     * @param[in] a 操作数1
     * @param[in] b 操作数2
     * @return 运算结果
     */
    template <typename A, typename B>
    decltype(A()+B()) operator()(const A &a, const B &b) const
    {
         return a+b;
    }
};

}}

#endif // ADD_H
