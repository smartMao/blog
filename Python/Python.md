##Python学习记录##

######来自网易云课堂-Python######

######Start time: 2015 - 07 - 23######


**2.2.1 算术运算符**

    只列出比较特殊的两个:
    
>- %   (取余)  例：10 % 3 = 1
>- **   (指数)    例: 2 ** 3 = 8   (表示2的3次方)

注意：在python 2 中 "/" 表示向下取整，两个整数相除，结果只能是整数，自动舍去小数部分，
      如果其中有一个数为浮点数，则结果为浮点数。
  >- 5 / 9 * ( 75 - 32 ) = 0
  >- 5.0 / 9 * ( 75 - 32 ) = 23.8888
                
定义：若参与运算的两个对象的类型相同，则结果类型不变
>- 1 / 2 = 0  (原本是等于0.5,但由于上面的定义)