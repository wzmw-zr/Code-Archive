# github使用与免密

## 一、免密与免登录

```shell
#免密
ssh-keygen -t rsa -C "your_email@example.com"
#免登录
git config --global user.name "wzmw-zr"
git config --global user.email "1767153298@qq.com"
git init #这个可有可不有
```

[your_email@example.com](mailto:your_email@example.com) 为你在 GitHub或者GitLab 注册时的邮箱。

回车后终端会显示： Created directory '/Users/xxx/.ssh'. Enter passphrase (empty for no passphrase): 提示你保存 .ssh/id_rsa 的路径是/Users/xxx/.ssh/id_rsa， 直接按回车。

之后去github上的`SSH and GPG keys`中创建新的SSH密钥，将~/.ssh/id_rsa.pub中的密钥拷贝一份粘贴到github上的SSH密钥栏即可。



## 二、git创建与使用仓库

```shell
git clone ssh-path
# or
git remote add origin ssh-path
#Remote更适用于将本地已经放置文件或项目的文件夹同步到GitHub上去 
#Clone是直接克隆线上的仓库 
git add file-or-directory
git commit -m "message"
git push -u branchname(origin) username(master)
git push
git remove file-or-directory
git rm file-or-directory
git pull
```



