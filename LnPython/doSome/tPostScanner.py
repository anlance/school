from socket import *
import threading
import argparse

lock = threading.Lock()
openNum = 0
threads = []

def postScanner(host,port):
    global openNum
    try:
        s = socket(AF_INET,SOCK_STREAM)
        s.connect((host,port))
        lock.acquire()
        openNum+=1
        print('[+] %d open' % port )
        lock.release()
        s.close()
    except:
        pass

    
def main():
    p = argparse.ArgumentParser(description='Post Scanner!.')
    p.add_argument('-H',dest='hosts',type=str)
    args = p.parse_args()
    hostList = '119.29.155.110'
    #hostList = args.hosts.split(',')  linux(?)
    setdefaulttimeout(1)
    for host in hostList:
        print('Scanning the host:%s......' % (host))
        for p in range(1,500):
            t = threading.Thread(target=postScanner,args=(host,p))
            threads.append(t)
            t.start()

        for t in threads:
            t.join()

        print('[*] The host:%s scan is complete!' % (host))
        print('[*] A total of %d open port' % (openNum))

if __name__ == '__main__':
    main()

