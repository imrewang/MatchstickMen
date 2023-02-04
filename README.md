# MatchstickMen
火柴人小游戏

## 一、简介

编写一个2D跑酷类游戏，游戏的主要思路为玩家可以通过键盘控制火柴人奔跑和跳跃，躲避蝙蝠到达终点。

## 二、部署

### （一）环境

编译器：Visual Studio 2019

配置EasyX

windows

### （二）部署截图

![部署截图](https://github.com/imrewang/MatchstickMen/blob/main/screenshot/%E9%83%A8%E7%BD%B2%E6%88%AA%E5%9B%BE.png?raw=true)

## 三、运行截图

![运行截图](https://github.com/imrewang/MatchstickMen/blob/main/screenshot/%E8%BF%90%E8%A1%8C%E6%88%AA%E5%9B%BE.png?raw=true)

![运行截图2](https://github.com/imrewang/MatchstickMen/blob/main/screenshot/%E8%BF%90%E8%A1%8C%E6%88%AA%E5%9B%BE2.png?raw=true)

## 四、总结

### （一）#物体间相互碰撞问题

两种方案

1.若是一个人物多个子弹，可以将子弹传入由人物遍历数组

2.若是多个人物多个子弹，可以由mainscene等，把人物、子弹传入，进行分析

### （二）绘图坐标问题

目前我遇到都是以左上角为基准画图或者放置图片

所以要左上角x,y坐标，物体图形长、宽，四个量，轻松确定一个图形位置

### （三）人物速度问题

有个固定重力加速度，由重力加速度改变速度，由速度改变坐标（嗯嗯，很符合物理学知识）

### （四）项目编写感悟

由简到繁。如果前面总体框架没有错的话，想加功能还是比较轻松的

### （五）异步输入问题

异步输入函数GetAsyncKeyState()，其可以同时识别两个按键被按下的情况

### （六）相对运动问题

让火柴人位置不变，一直保持在画面中间，而让背景、地面做相对运动的问题

根据若火柴人移动，应该有的偏移，反向推出现在地块的偏移

后面大背景可以只进行小幅度偏移

注意：实际只在绘图是加上偏移

例

~~~
putimage(left_x-px,top_y-py,&im_land); // 角色不动，绘制地面有一个偏移量

// 背景偏移量/20，就形成了有深度差的前后景的视觉效果        
putimage(-px/20, -100-py/20, &im_bk);   

// 游戏中显示角色，角色不动，地面、背景相对运动        
putimagePng(WIDTH/2,HEIGHT/2-height,&im_show); 
~~~

## 五、改进方向

（1）添加更多地图元素，比如陷阱、动态障碍物、怪物、金币等。

（2）实现游戏地图设计、分数统计等功能。
