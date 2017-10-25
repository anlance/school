from socket import *

def postScanner(host,port):
    try:
        s = socket(AF_INET,SOCK_STREAM)
        s.connect((host,port))
        print('[+] %d open' % port )
        s.close()
    except:
        print('[-] %d close' % port)

def main():
    setdefaulttimeout(0.0000001)
    for p in range(1,1024):
        postScanner('192.168.0.100',p)

if __name__ == '__main__':
    main()