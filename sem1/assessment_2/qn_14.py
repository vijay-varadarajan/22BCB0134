import csv

def main():
    customers = int(input("Customers: "))
    net_total = 0
    with open("products.csv", 'w') as file:
        writer = csv.DictWriter(file, fieldnames=['custid','prod','quantity','rate','total'])
        for i in range(customers):
            products = int(input("Products: "))
            custid = int(input("Id: "))
            for j in range(products):
                prod = input("Product: ")
                quantity = int(input("Quantity: "))
                rate = float(input("Rate: "))
                total = rate * quantity
                net_total += total
                writer.writerow({"custid":custid, "prod":prod, "quantity":quantity, "rate":rate, "total":total})
        writer.writerow({"custid":f'TotalAmount: Rs:{net_total}'})


def fn1(id):
    cust_total = 0
    with open('products.csv', 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            if row['customerId'] == id:
                cust_total += int(row['TotalPrice'])
    return cust_total


def fn2():
    max_order_count = 0
    max_order = []
    min_order_count = 0
    min_order = []
    with open('products.csv', 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            if int(row['quantity']) > int(max_order_count):
                max_order_count = row['quantity']
        for row in reader:
            if row['quantity'] == max_order_count:
                max_order.append(row['Product'])
        min_order_count = max_order_count
        for row in reader:
            if int(row['quantity']) < int(min_order_count):
                min_order_count = row['quantity']
        for row in reader:
            if row['quantity'] == min_order_count:
                min_order.append(row['Product'])
    return max_order, min_order


def fn3():
    customer_max = []
    max_orders, min_orders = fn2()
    with open('products.csv', 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            if row['quantity'] == max_orders:
                customer_max.append(row['customerId'])
    return customer_max

if __name__ == "__main__":
    main()
