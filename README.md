# OS_HW_Shell_it_2

*在 Level2 中，本 Shell 應具備 Level1 的基礎，並將 Level1 的第 2,3 兩項改
寫成程式的執行。
1. 可以接收並執行任意不帶參數的指令。舉例：
ichenyeh@/home/OS/> ls 
<< 使用者輸入 ls 並按下 Enter
接著你便透過你的 shell 來建立一個新的 ls 程序，並將輸出導向標準輸出（於文字介面
上輸出）

2. 可以接收並任何帶有參數的指令。舉例：
ichenyeh@/home/OS/> ls -al 
<< 使用者輸入 ls 並加上附加參數 "-al" 最後按下 Enter
接著你便透過你的 shell 來建立一個新的 ls 程序，執行時給與-al 這個參數，並將最終輸
出導向標準輸出

3. 可以將多個不同的指令串接起來，提供 pipe ‘|’的功能，讓使用者可以將一個程式的
輸出(standard output)接到另一個程式的輸入，需要支援多個程式串接（最多四個）。
舉例：ls –al | more （將 ls 的輸出導向程式 more 的輸入）
舉例：ps –ef | grep svn | more


4. 提供 redirect ‘<, >, 1>, 2> … ’的功能讓程式將標準輸出、標準錯誤輸出等重新導向
到新目的地（作業中只測試從檔案導入或導出到檔案，但會跟 pipe 混合運用）
舉例：ls –al > ~/logfile.t (將輸出導向一個檔案)
以上行為可參考這邊的說明:
(更多 pipe/redirect 使用說明) http://ryanstutorials.net/linuxtutorial/piping.php

5. （加分項目）實做以下現代 Shell 都會包含的一些輔助功能
A. 提供使用者可以用方向按鍵（上下）來瀏覽之前輸入過的指令，
B. 使用 Tab（或是雙擊 Tab）來進行檔名自動完成
提示：推薦使用 readline 這個函式庫來達成
