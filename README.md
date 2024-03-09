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
 ## After PR => "Continuous integration has not been set up"
      => open Actions
      => choose "i understand...enable"
 ## After merging, the origin has changed the code but your local copy hasn't been updated
      => To retrieve the changes, type '$ git pull'
      => git add 
      => git commit -m "recommend"
      =>git pull origin "name_branch"
      => Close or quit the screen(see a green screen)
   ==> The changes have now been successfully retrieved
