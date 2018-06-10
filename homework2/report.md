# EDA 第五章

马子轩 2015012283

### 9

$x_2\cdot\overline{x_4}+\overline{x_1}\cdot\overline{x_2}\cdot\overline{x_3}\cdot x_4$

### 13

TFFFT

### 16

Intersection:
X011
00X1
0X11
001X
X111
0000
Union:
X0X1
0X1X
X1XX
XX11
00XX

### 17

cube.cpp

两个集合立方体个数

每个立方体的x0,y0,z0,x1,y1,z1

```
g++ cube.cpp --std=c++11
```

### 18-19

logic.cpp

两个表达式个数 维数

每个表达式

```shell
g++ logic.cpp --std=c++11
```

### 20

1 #={X101|1uu} @#={X101|1uu}

2 #={01100|u0uu, XX101|100u, X010X|100u, 0X10X|100u} @#={01100|u0uu, XX101|100u, 1010X|100u,01101|100u}

3 #={01X10|uu0u} @#={01X10|uu0u}

### 23

1 0XX0

2 $\empty$

3 $\empty$

### 25

广义星积

C={1XX1X,0XX0X,X0XX1,111X1}

B0={XXX0X}

B1={XXX1X,X11X1}

S(B0∩B1)={X1101} 

C={1XX1X,0XX0X,X0XX1,111X1,X1101}

B0={XXXX1}

B1={1X1X1,XX101}

S(B0∩B1)={1X1X1,XX101}

C={1XX1X,0XX0X,X0XX1,1X1X1,XX101}

B0=Φ

B0={0XXXX,XX1X1}

B1={1XXXX}

S(B0∩B1)={1X1X1}

C={1XX1X,0XX0X,X0XX1,1X1X1,XX101}

B0=Φ

Z={1XX1X,0XX0X,X0XX1,1X1X1,XX101}



锐积法
Coff={1XX0X, 0XX1X}∩{X1XX1,XXXX0}∩{XXXX0,XX0X1,X01X1,011X1}={11001,1XX00,01X11,0XX10}
Z=XXXXX#11001#1XX00#01X11#0XX10={0XX0X,X0XX1,1X1X1,XX101,1XX1X}

### 28

X0X1={1,3,9,11},3

X01X={2,3,10,11},3

0X11={3,7},4

1X0X={8,9,12,13},3

10XX={8,9,10,11},3

1仅被X0X1覆盖

2仅被X01X覆盖

7仅被0X11覆盖

13仅被1X0X覆盖

M={X0X1,X01X,0X11,1X0X}

### 选拔法

3(1)是考虑p∈M的情况，而!p∈M的情况也应当考虑，所以在3(1)(2)取较优的结果.