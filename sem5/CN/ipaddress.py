import regex

def ip_to_bin_octets(ip):
    return ''.join(f'{int(octet):08b}' for octet in ip.split('.'))

def bin_octets_to_ip(bin_ip):
    return '.'.join(str(int(bin_ip[i:i+8], 2)) for i in range(0, len(bin_ip), 8))

def output(ip):
    ipclass = 'A'
    allbytes = list()

    if bytes := regex.match(r'([0-9]{1,3}).([0-9]{1,3}).([0-9]{1,3}).([0-9]{1,3})', ip):
        allbytes = [bytes[1], bytes[2], bytes[3], bytes[4]]
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
        netid = ''
        defmask = ''
        
        net_bytes = ord(ipclass) - ord('A') + 1
        
        for i in range(net_bytes):
            netid += allbytes[i] + '.'
            defmask += '255.'
        netid = netid[:-1]
        
        hostid = '.'.join(allbytes[net_bytes:])

        firstaddr = netid + '.' + '.'.join(['0'] * (4 - net_bytes))
        lastaddr = netid + '.' + '.'.join(['255'] * (4 - net_bytes))

        defmask = defmask + '.'.join(['0'] * (4 - net_bytes))

        subnets = int(input("Number of subnets: "))
        
        subnet_bits = (subnets - 1).bit_length()
        
        custom_mask = '1' * (8 * net_bytes + subnet_bits) + '0' * (32 - (8 * net_bytes + subnet_bits))
        custom_subnet_mask = bin_octets_to_ip(custom_mask)
        
        host_bits = 32 - (8 * net_bytes + subnet_bits)
        num_hosts_per_subnet = 2 ** host_bits - 2

        block_size = 2 ** host_bits

        print(f"\nCustom Subnet Mask: {custom_subnet_mask}")
        print(f"Number of Hosts per Subnet: {num_hosts_per_subnet}")
        
        network_prefix = ip_to_bin_octets(netid)[:8 * net_bytes]
        
        for i in range(subnets):
            subnet_prefix = network_prefix + format(i, f'0{subnet_bits}b')
            
            first_host = subnet_prefix + '0' * host_bits
            first_usable = bin(int(first_host, 2) + 1)[2:].zfill(32)
            
            last_host = subnet_prefix + '1' * host_bits
            last_usable = bin(int(last_host, 2) - 1)[2:].zfill(32)
            
            print(f"Subnet {i + 1}:")
            print(f"  Network Address: {bin_octets_to_ip(first_host)}")
            print(f"  First Usable Address: {bin_octets_to_ip(first_usable)}")
            print(f"  Last Usable Address: {bin_octets_to_ip(last_usable)}")
            print(f"  Broadcast Address: {bin_octets_to_ip(last_host)}\n")
        
        return f"Class = {ipclass} \nNetid = {netid} \nHostid = {hostid} \nDefault mask = {defmask} \nFirst address = {firstaddr} \nLast address = {lastaddr}"

    else:
        return f"Class = {ipclass}"

def main():
    ip = input("Enter IP address: ")
    print(output(ip))
    
if __name__ == "__main__":
    main()