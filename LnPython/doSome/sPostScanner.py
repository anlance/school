from socket import *
import threading

lock = threading.Lock()
openNum = 0
threads = []

def postScanner(host,port):
    global openNum
    try:
        s = socket(AF_INET,SOCK_STREAM)
        s.connect((host,port))
        lock.acquire()
        openNum += 1
        print('[+] %d open' % port )
        lock.release()
        s.close()
    except:
        pass

def main():
    setdefaulttimeout(1)
    for p in range(0,500):
        t = threading.Thread(target=postScanner,args=('119.29.155.110',p))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    print('[*] The scan is complete !')
    print('[*] A total of %d open port' % (openNum))


if __name__ == '__main__':
    main()