import regex

def ip_to_bin_octets(ip):
    """Converts an IP address into its binary octet representation."""
    return ''.join(f'{int(octet):08b}' for octet in ip.split('.'))

def bin_octets_to_ip(bin_ip):
    """Converts binary octets to dotted decimal notation."""
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
        
        # Determine the number of bytes in the network part
        net_bytes = ord(ipclass) - ord('A') + 1
        
        # Construct the NetID and Default Mask
        for i in range(net_bytes):
            netid += allbytes[i] + '.'
            defmask += '255.'
        netid = netid[:-1]
        
        # Calculate the default host part for the given class
        hostid = '.'.join(allbytes[net_bytes:])

        # Default first and last address
        firstaddr = netid + '.' + '.'.join(['0'] * (4 - net_bytes))
        lastaddr = netid + '.' + '.'.join(['255'] * (4 - net_bytes))

        defmask = defmask + '.'.join(['0'] * (4 - net_bytes))

        # Get the number of subnets
        subnets = int(input("Number of subnets: "))
        
        # Calculate the number of bits needed for subnets
        subnet_bits = (subnets - 1).bit_length()
        
        # Custom subnet mask
        custom_mask = '1' * (8 * net_bytes + subnet_bits) + '0' * (32 - (8 * net_bytes + subnet_bits))
        custom_subnet_mask = bin_octets_to_ip(custom_mask)
        
        # Calculate the number of hosts per subnet
        num_hosts_per_subnet = 2 ** (32 - (8 * net_bytes + subnet_bits)) - 2

        # Calculate subnets and corresponding address ranges
        print(f"\nCustom Subnet Mask: {custom_subnet_mask}")
        print(f"Number of Hosts per Subnet: {num_hosts_per_subnet}")
        
        # Generate subnet address ranges
        for i in range(subnets):
            base_subnet = ip_to_bin_octets(netid)[:8 * net_bytes + subnet_bits] + f'{i:0{32 - (8 * net_bytes + subnet_bits)}b}'
            subnet_first_ip = base_subnet[:-len(f'{num_hosts_per_subnet:b}')] + '0' * len(f'{num_hosts_per_subnet:b}')
            subnet_last_ip = base_subnet[:-len(f'{num_hosts_per_subnet:b}')] + '1' * len(f'{num_hosts_per_subnet:b}')
            
            print(f"Subnet {i + 1}:")
            print(f"  First Address: {bin_octets_to_ip(subnet_first_ip)}")
            print(f"  Last Address: {bin_octets_to_ip(subnet_last_ip)}\n")
        
        return f"Class = {ipclass} \nNetid = {netid} \nHostid = {hostid} \nDefault mask = {defmask} \nFirst address = {firstaddr} \nLast address = {lastaddr}"

    else:
        return f"Class = {ipclass}"

def main():
    ip = input("Enter IP address: ")
    print(output(ip))
    
if __name__ == "__main__":
    main()
