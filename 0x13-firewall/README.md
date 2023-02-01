# 0x13 - Firewall

Simple firewall configurations on web server using ufw. This project consists of the following two(2) tasks:

### Tasks 0. Block all incoming traffic but
In this project, the ufw firewall was installed and setup to block incoming traffic, except the following TCP ports:
 - 22 (SSH)
 - 443 (HTTPS SSL)
 - 80 (HTTP)

### Task 1. Port forwading

The ufw firewall was configured to redirects port 8080/TCP to port80.
The steps to fully solving this task are as follows:
- Login to the web-01 server.
- If ufw firewall is not installed and basically configured do so and enable it.
- Navigate and edit the configuration file /etc/ufw/before.rules
- Append the following lines to the aforementioned configuration file:

*nat
:PREROUTING ACCEPT [0:0]
-A PREROUTING -p tcp --dport 8080 -j REDIRECT --to-port 80
COMMIT

Set/Edit /etc/sysctl.conf as follows:
net.ipv4.ip_forward=1

save and close the file and Reload changes.
sudo sysctl -p

Restart firewall
sudo service ufw restart

Test
netstat -lpn
sudo iptables -t nat -L -n -v


https://www.cyberciti.biz/faq/how-to-configure-ufw-to-forward-port-80443-to-internal-server-hosted-on-lan/
