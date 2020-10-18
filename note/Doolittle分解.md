# Doolittle分解

对于线性方程
$$
\begin{cases}
    a_{11}x_1+a_{12}x_2+\dots a_{1m}x_m=b_1  \\
    a_{21}x_1+a_{22}x_2+\dots a_{2m}x_m=b_2  \\
    a_{31}x_1+a_{32}x_2+\dots a_{3m}x_m=b_3  \\
    \dots \\
    a_{n1}x_1+a_{n2}x_2+\dots a_{nm}x_m=b_n  \\
\end{cases}
$$
有系数矩阵 $A$ 和常数项列矩阵 $B$
$$
A^{(1)}=\begin{bmatrix}
    a_{11} & a_{12} & a_{13} & \dots & a_{1m} \\
    a_{21} & a_{22} & a_{23} & \dots & a_{2m} \\
    a_{31} & a_{32} & a_{33} & \dots & a_{3m} \\
    \vdots \\
    a_{n1} & a_{n2} & a_{n3} & \dots & a_{nm} \\
\end{bmatrix}, \ 
B^{(1)}=\begin{bmatrix}
    b_1 \\
    b_2 \\
    b_3 \\
    \vdots \\
    b_n
\end{bmatrix}
$$
**Step 1**
设初等变换阵
$$
L_1^{-1}=\begin{bmatrix}
    1 \\
    -l_{21} & 1 \\
    -l_{31} & 0 & 1 \\
    \vdots & \vdots & \vdots & \ddots \\
    -l_{n1} & 0 & 0 & \dots & 1
\end{bmatrix}, \ 
l_{i1}=\frac{a_{i1}}{a_{11}}, \ i=2,3,4,\dots,n
$$
令
$$
A^{(2)}=L_1^{-1}A^{(1)}, \ B^{(2)}=L_1^{-1}B^{(1)}
$$
**Step 2**
设
$$
L_2^{-1}=\begin{bmatrix}
    1 \\
    0 & 1 \\
    0 & -l_{32} & 1 \\
    \vdots & \vdots & \vdots & \ddots \\
    0 & -l_{n2} & 0 & \dots & 1
\end{bmatrix}, \ 
l_{i1}=\frac{a_{i2}}{a_{12}}, \ i=3,4,5,\dots,n
$$
令
$$
A^{(3)}=L_1^{-1}A^{(2)}, \ B^{(3)}=L_1^{-1}B^{(2)}
$$
以此类推, 第 $n-1$ 步消元后有
$$
A^{(n)}=L_1^{-1}A^{(n-1)}, \ B^{(n)}=L_1^{-1}B^{(n-1)}
$$
令
$$
U=A^{(n)}
$$
则
$$
\begin{cases}
    L_{n-1}^{-1}L_{n-2}^{-1} \dots L_2^{-1}L_1^{-1}A^{(1)}=U \\
    L_{n-1}^{-1}L_{n-2}^{-1} \dots L_2^{-1}L_1^{-1}B^{(1)}=B^{(n)}
\end{cases}
$$
可导出LU分解式
$$
L=\begin{bmatrix}
    1 \\
    l_{21} & 1 \\
    l_{31} & l_{32} & 1 \\
    \vdots & \vdots & \vdots & \ddots \\
    l_{n1} & l_{n2} & l_{n3} & \dots & 1
\end{bmatrix}, \ 
U=\begin{bmatrix}
    u_{11} & u_{12} & u_{13} \dots u_{1n}
\end{bmatrix}
$$
