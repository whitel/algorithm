## 01背包问题

+ 为n行W列的二维数组

+ 把所有`dp[0][i]`与`dp[k][0]`下标初始化为0

+ 计算从1~n，1~W的数值

+ 状态转移方程：

  ```
  // 装得下再进行大小判断
  if(k-weight[i]>=0) {
  	// 看看这个物品装不装的好？
  	dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
  } else {
  	// 当前物品装不下了
  	dp[i][j] = dp[i-1][j];
  }
  ```

  

+ 行表示第i个物品，列表示当前背包的重量



## 参考文献

+ https://www.cnblogs.com/kkbill/p/12081172.html
