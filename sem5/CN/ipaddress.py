import regex
    
def output(ip):
    ipclass = 'A'
    allbytes = list()

    if bytes := regex.match(r'([0-9]{0,3}).([0-9]{0,3}).([0-9]{0,3}).([0-9]{0,3})', ip):
        allbytes = bytes
        firstbyte = int(bytes[1])
        if 0 <= firstbyte <= 127:
            ipclass = 'A'
        elif 128 <= firstbyte <= 191:
            ipclass = 'B'
        elif 192 <= firstbyte <= 223:
            ipclass = 'C'
        elif 224 <= firstbyte <= 239:
            ipclass = 'D'
        elif 240 <= firstbyte <= 255:
            ipclass = 'E'
        else:
            return f'Invalid IP address {ip} 1'
    else:
        return f'Invalid IP address {ip} 2'
    
    if ipclass in ['A', 'B', 'C']:
        defmask = ''
        
        netid = ''
        for i in range(1, ord(ipclass) - ord('A') + 2):
            netid += allbytes[i]
            netid += '.'
            defmask += '255.'
        netid = netid[:-1]
        
        firstaddr, lastaddr = netid, netid
            
        hostid = ''
        for i in range(ord(ipclass) - ord('A') + 2, 5):
            hostid += allbytes[i]
            hostid += '.'
            
            firstaddr += '.0'
            lastaddr += '.255'
            
            defmask += '0.'
        hostid = hostid[:-1]
        
        defmask = defmask[:-1]
        
        subnets = input("Number of subnets: ")
        
        # print the custom subnet mask and first and last ip addresses in each subnet 
        
        
        return f"Class = {ipclass} \nNetid = {netid} \nHostid = {hostid} \nDefault mask = {defmask} \nFirst address = {firstaddr} \nLast address = {lastaddr}"

    else:
        return f"Class = {ipclass}"

def main():
    ip = input("Enter IP address: ")
    print(output(ip))
    
if __name__ == "__main__":
    main()
    