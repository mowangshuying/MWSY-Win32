# MwsyWin32 项目开发说明文件

## Win32 控制台项目

### Cs_CreateStruct

* 创建了Student结构体、赋值、打印值
* 简要代码如下

![image-20220415002204320](./doc/image-20220415002204320.png)

* 思路：主要是利用如下语句，对Student结构体进行赋值

  ```
  Student sd = {1,2,3,4};
  ```

* 结果

  ![image-20220415002438410](./doc/image-20220415002438410.png)

  

### Cs_DestroyClass

* 主要查看是否调用了类的析构函数

* 关键代码如下

  ![image-20220415002838482](./doc/image-20220415002838482.png)

  ![image-20220415003028746](./doc/image-20220415003028746.png)

* 结果：

  ![image-20220415003126815](./doc/image-20220415003126815.png)

  ## Win32 应用程序(界面程序)
  
  ### Vc_HelloWorld 利用向导直接生成的HelloWorld应用程序
  
  ![image-20220430095707990](./doc/image-20220430095707990.png)

### VC_Button 在win32中展示按钮

![image-20220430095956875](./doc/image-20220430095956875.png)

### Vc_ComboBox win32使用comboBox控件

![image-20220430100125961](./doc/image-20220430100125961.png)

### Vc_Edit win32使用edit控件

![image-20220430100312415](./doc/image-20220430100312415.png)

### Vc_InWnd win32中窗口中在嵌入一个窗口

![image-20220430100433228](./doc/image-20220430100433228.png)

### Vc_ListBoxView win32中使用ListBoxView

![image-20220430100559691](./doc/image-20220430100559691.png)

### Vc_menu Win32中使用右键菜单

![image-20220430100708152](./doc/image-20220430100708152.png)

### Vc_ModelessDlg win32中使用模式对话框

![image-20220430100826339](./doc/image-20220430100826339.png)

### Vc_ProgressBar win32中使用进度条

![image-20220430100826339](./doc/gif-202204301020.gif)

### Vc_RichEdit 富文本框

### Vc_TreeList win32中使用树形控件

![image-20220430102227997](./doc/image-20220430102227997.png)

### Vc_Timer win32中使用定时器

![image-20220430102351736](./doc/image-20220430102351736.png)