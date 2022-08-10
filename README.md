# subwaySystem-Changsha
## **序言**
这是基于Qt的长沙换乘系统，包含添加站点、添加线路、连接线路、换乘查询、景点查询、广告系统、线路图查询等功能。
***
## **开发环境**
- 开发平台：
- 计算机型号	：戴尔G15
- 计算机内存	：16.00GB
- CPU			：R75800-H
- 操作系统	：Windows 11 家庭版
- 开发语言	：C++（C++11标准以上）
- 开发框架	：QT
- 集成开发环境：Qt Version 5.12.0
- 编译器		：MinGW 64bit
- 运行环境：
	- 可在上述集成环境下运行；
	- 通过windeployqt.exe及Easy Setup进行整合压缩为发布为了一个长沙地铁换乘系统.exe文件，可在普通windows机型下运行。


## **部分功能介绍**

- **换乘查询**
1. 点击右侧换乘按钮或选择功能中的换乘线路查询或直接按快捷键ctrl+T打开; 
2. 选择方式有“较快捷(最短时间)”和“少换乘(最少换乘)”; 
3. “较快捷”换乘指南线路为依次乘坐的详细站点路线; 
4. “少换乘”换乘指南线路为换乘的关键站点; 
5. 换乘后，可以点击重置按钮，左侧的线路图将恢复原样; 
6. 请输入正确存在的起点站和终点站，否则程序会提示重新输入; 
7. 若站点之间目前没有线路连接则会提示重新输入; 

- **添加站点**
1. 点击右侧添加站点按钮或选择功能中的添加站点或直接按快捷键ctrl+U; 
2. 先输入站点名称，再选择新站点的经纬度; 
2. 然后选择站点所属线路; 
3. 最后点击添加站点即可;
4. 添加的站点会在主界面的线路网络图中显示出来; 

- **添加线路**
1. 点击右侧添加线路按钮或选择功能中的添加线路或直接按快捷
ctrl+Y; 
2. 先添加新线路信息; 
3. 然后点击添加线路按钮即可添加一条新线路; 
4. 若想添加这条线路上的两个站点，则先在添加站点添加两个新站点，然后回到此界面在下方连接站点界面连接这两个点即可; 

- **景点查询**
1. 选择菜单栏中的查看景点查询或直接按快捷键ctrl+G打开; 
2. 输入想要查询的站点，则会自动显示出附件的景点 

## **部分界面模块展示**

- **主界面模块**
### ![image](https://user-images.githubusercontent.com/91833429/183796783-abb5ea24-e372-4eea-b354-5c6c66d8bc6c.png)

- **换乘查询模块**

### ![image](https://user-images.githubusercontent.com/91833429/183797171-0934d38e-aabb-42dd-8458-7667b7cd7142.png)

## **声明**
### 部分源代码借鉴网络，侵删。
### 图片图标来源于网络，侵删。
### 本项目不用作于商业用途，如有商业需求，请与我联系。











