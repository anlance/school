import requests
from bs4 import BeautifulSoup
from lxml import etree
import time
import re
import json

ori_url = 'http://esf.cd.fang.com'
ua = 'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36'
headers = {
    'User-Agent': ua
}

def average(array):
    avg = 0.0
    n = len(array)
    for num in array:
        avg+= 1.0*num/n
    return int(avg)

def get_subway(ori_url):
    '''
    获取所有的地铁线和地铁线的url
    :param ori_url: 成都二手房的url
    :return: 地铁线的列表，每个元素是地铁线的名称和地铁线的url的键值对
    '''
    res = requests.post(ori_url, headers=headers)
    soup = BeautifulSoup(res.content.decode('gbk'),'lxml')
    subway_obj = soup.find('div',class_='screen_al',id = 'list_D02_20')
    subway_obj_list = subway_obj.find_all('li')[0].select('a')
    sub_list = []
    for i in range(len(subway_obj_list)):
        if i == 0:  #第一个是'不限'，不是地铁线
            continue
        sub_name = subway_obj_list[i].get_text()
        sub_url = subway_obj_list[i].attrs['href']
        sub = {
            sub_name: sub_url
        }
        sub_list.append(sub)
    return  sub_list

def get_allnum_in60(subway):
    '''
    得到每条地铁线的60万以下的二手房的总数目
    :param subway:每条地铁线的字典
    :return:每条地铁线的名字, 60万以下的二手房的总数目
    '''
    sub_name = ''
    sub_url = ''
    for key in subway:
        sub_name = key
        sub_url = subway[key]
    in60_url = 'c20-d260'
    current_url = ori_url+sub_url+in60_url
    res = requests.post(current_url, headers=headers)
    soup = BeautifulSoup(res.content.decode('gbk'), 'lxml')
    house = soup.find('div', class_='shop_list shop_list_4').find_all('dt')
    house_num = len(house)  #得到第一页的house数目
    page_info = soup.find('div',class_='page_al').find_all('p')
    last_page_url = page_info[-2].a.attrs['href']
    last_page_url = ori_url + last_page_url #得到末页的链接

    res = requests.get(last_page_url)
    soup = BeautifulSoup(res.content.decode('gbk'), 'lxml')
    page_num = int(soup.find('div',class_='page_al').find_all('span')[-1].get_text())   #得到页数
    house = soup.find('div', class_='shop_list shop_list_4').find_all('dt')
    last_page_house_num = len(house)     #得到z最后一页的house数目
    return sub_name, (page_num-1)*house_num+last_page_house_num

def get_price_and_year(subway, page):
    '''
    得到每条地铁线的二手房的最高或者最低的单价
    :param subway:  每条地铁线的字典
    :param index: 前几页的数据
    :return:
    '''
    sub_name = ''
    sub_url = ''
    build_year = []
    single_price = []
    for key in subway:
        sub_name = key
        sub_url = subway[key]
    price_num = []
    for i in range(page):
        cur_sub_url = ori_url + sub_url +'i3'+ str(i+1)
        res = requests.post(cur_sub_url, headers=headers)

        # 用xpath 来获取每条地铁线的每套二手房的单价
        etree_obj = etree.HTML(res.text)
        price = etree_obj.xpath("//div[@class='shop_list shop_list_4']/dl/dd[last()]/span[last()]/text()")
        for item in price:
            str_price = str(item).split('元')[0]
            price_num = int(str_price)  #转成整数
            if price_num > 100000:  #去掉系统异常数据
                continue
            single_price.append(price_num)  #保存已有的单价

        year = etree_obj.xpath("//div[@class='shop_list shop_list_4']/dl/dd[1]/p[1]")
        patter = "\d{0,4}年"
        for i in year:
            year_str = str(i.xpath('./text()')) #将列表转换成字符串
            year_str = re.findall(patter,year_str)
            if len(year_str) == 0:
                continue
            year_num = int(year_str[0].split('年')[0])   #转成整数
            build_year.append(year_num)     #保存已有的修建年份

    avg_price = average(single_price)
    avg_year = average(build_year)
    return sub_name, avg_price, avg_year

def main_sub_way():
    sub_list = get_subway(ori_url)
    print('成功获取地铁线的名字和链接......')
    pie_data_list = []
    sub_house_info = []
    sub_name_list = []
    avg_price_list = []
    avg_year_list = []
    for subway in sub_list:
        sub_name, house_num = get_allnum_in60(subway)
        # get_allnum_in60(subway)
        # print(house_num)
        # page = int(input('页数')) #传入页数
        page = 2  # 默认两页
        sub_name2, avg_price, avg_year = get_price_and_year(subway, page)
        sub_name_list.append(sub_name)
        avg_price_list.append(avg_price)
        avg_year_list.append(avg_year)
        print('成功获取'+str(sub_name)+'周围的二手房信息......')
        pie_data = {
            'value':house_num,
            'name':sub_name
        }
        pie_data_list.append(pie_data)

        data = {
            '地铁线': sub_name,
            '60万以下': str(house_num)+' 套',
            '平均单价': str(avg_price)+' 元/平方米',
            '平均修建年份': str(avg_year)+' 年'
        }
        sub_house_info.append(data)
        time.sleep(3)
    pie_data_str = json.dumps(pie_data_list, ensure_ascii=False)
    sub_house_info_str = json.dumps(sub_house_info, ensure_ascii=False)
    with open('../file/subway.json', 'wb') as fp:
        fp.write(sub_house_info_str.encode())
    with open('../file/pie.json', 'wb') as fp:
        fp.write(pie_data_str.encode())
    print('成功保存到subway.json和pie.json中......')
    print(' ')
    print('--------------以下数据打印方便作图---------------')
    print('地铁线名字：'+str(sub_name_list))
    print('对应的平均单价：'+str(avg_price_list))
    print('对应的平均修建年份：'+str(avg_year_list))

