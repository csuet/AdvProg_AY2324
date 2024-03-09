## HOW TO UP CODE TO GIT 
* open new command in folder
* $ git init
* $ git add <file_name> or git add . (add everything)
* $ git commit -m "label"
* $ git remote add origin <link repo>
* $ git branch -M main
* $ git push -u origin main (-f(force))
* IF error non-fast-forward ==> git pull origin main (git pull --rebase origin main)

## BRANCH
* $ git checkout -b <name branch> (=> Switched to a new branch 'name branch')
* $ git branch (to check branch)
## Change the Remote URL
  * $ open new command in folder
  * $ git remote -v
  * $ git remote set-url origin "link.git"
  * $ git add <file_name>or git add .
  * $ git commit -m "your commit / recommend for commit"
  * $ git push origin master
## HOW TO CLONE 
  * $ fork the another github
  * $ open new command in folder
  * $ git clone "link_fork.git"
  * $ git checkout -b "branch"
  * $ git add
  * $ git commit
  * $ git push origin "name_branch"
  * # Nếu sau khi PR, có hiện ra "Continuous integration has not been set up"
      => vào Actions
      => chọn "i understand...enable"
  * # Lỡ sau khi ấn merge => origin đã thay đổi code, nhưng local chưa thay đổi
      => muốn lấy về thì nhấn gõ '$ git pull'
      => git add 
      => git commit -m "recommend"
      =>git pull origin "tên nhánh"
      => (có thể hiện ra màn hình xanh)
      => close(quit)
      => đã lấy được về
