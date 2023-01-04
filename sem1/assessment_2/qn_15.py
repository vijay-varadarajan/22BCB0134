import sys

HOSUR_COST = 75
VANIYAMBADI_COST = 250
VELLORE_COST = 500
WALAJA_COST = 600
CHENNAI_COST = 750

def main():
    REGULAR = 12
    TATKAL = 3
    SEAT_NO = 15

    username = input('Username: ')
    password = input('Password: ')

    given_creds = []
    with open('credentials.txt', 'r') as file:
        lines = file.read()
        creds = lines.split(',')
        for cred in creds:
            if '\n' in cred:
                spl = cred.split('\n')
            else:
                spl = cred.strip()
            if type(spl) == list:
                for i in spl:
                    given_creds.append(str(i).strip())
            else:
                given_creds.append(spl)

    check_user = False
    check_pass = False
    for i in range(0, len(given_creds), 2):
        if given_creds[i] == username:
            check_user = True
            break
    for i in range(1, len(given_creds), 2):
        if given_creds[i] == password:
            check_pass = True
            break

    if not check_pass or not check_user:
        print("Invalid Credentials")
        sys.exit(1)

    details = []
    output = ''

    while True:
        try:
            menu_option = int(input("Menu option: "))
            passengers, dest, date, date_date = 0, '', '', 0
            if menu_option == 1:
                booking_option = input('Booking option: ').strip()
                if booking_option == 'A' or booking_option == 'B':
                    passengers = int(input('Passengers: ').strip())
                    short_details = []
                    for i in range(passengers):
                        name, age = input().strip().split(',')
                        short_details.append({'name':name, 'age': int(age), 'booking_option': booking_option, 'destination': dest, 'date': date})

                    dest = input('Destination: ').strip()
                    date = input("Date: ")
                    for j in short_details:
                        j['destination'] = dest
                        j['date'] = date

                    details += short_details

                    date_date = int(date.split('-')[0])
                else:
                    print("INVALID OPTION")
                    sys.exit(1)
                
                if booking_option == 'A':
                    REGULAR -= passengers
                    if REGULAR < 0:
                        output += "insuffient seats!!! Try for other dates...\n"
                        break
                elif booking_option == 'B':
                    TATKAL -= passengers 
                    if TATKAL < 0:
                        output += "insuffient seats!!! Try for other dates...\n"
                        break

                output += f"Remaining seats:\nRegular = {REGULAR}\nTatkal = {TATKAL}\nPassessnger Name - Age - Source - Destination - Seat No\n"

                for detail in short_details:
                    output += f"{detail['name']} - {detail['age']} - Bengaluru - {dest} - {SEAT_NO}\n"
                    SEAT_NO -= 1
            
                output += f"Date of journey: {date}\ntotal fare = Rs. {calc_total_fare(booking_option, dest, short_details)}\n\n"

            elif menu_option == 2:
                name = input().strip()
                age = int(input().strip())
                cancel_date = input('Cancellation date: ')
                cancel_date_date = int(cancel_date.split('-')[0])

                new_date_date = 0
                for detail in details:
                    if detail['name'] == name and detail['age'] == age:
                        new_date_date = int(str(detail['date']).split('-')[0])
                        break
                
                refund_amount = calc_refund_amount(details, name, age, new_date_date, cancel_date_date)
                for detail in details:
                    if detail['name'] == name and detail['age'] == age:
                        details.remove({'name': name, 'age': age, 'booking_option': detail['booking_option'], 'destination': detail['destination'], 'date': detail['date']})
                        break
                
                output += f"Remaining seats:\nRegular = {REGULAR}\nTatkal = {TATKAL}\nNumber of Passengers to cancel = 1\nCancelled passenger name = {name}\nCancelled Passenger age = {age}\nRefund amount = Rs. {refund_amount}\nCancellation Charge = Rs. {refund_amount}\n"
                
            elif menu_option == 3:
                break

            else:
                print("Invalid option")
                sys.exit(1)
        except :
            break
    
    print(output)
    with open('reservations.txt', 'w') as file:
        file.write(output)


def calc_refund_amount(details, name, age, new_date_date, cancel_date_date):
    days_bween = new_date_date - cancel_date_date
    fare, total_fare = 0, 0
    for detail in details:
        if detail['name'] == name and detail['age'] == age:
            total_fare = 0
            addt_cost = 0
            dest = detail['destination']
            if detail['booking_option'] == 'B':
                addt_cost = 100
            
            if detail['age'] < 60:
                if str(dest).lower() == "hosur":
                    total_fare += HOSUR_COST
                elif str(dest).lower() == "vaniyambadi":
                    total_fare += VANIYAMBADI_COST
                elif str(dest).lower() == "vellore":
                    total_fare += VELLORE_COST
                elif str(dest).lower() == "walaja":
                    total_fare += WALAJA_COST
                elif str(dest).lower() == "chennai":
                    total_fare += CHENNAI_COST
            elif detail['age'] >= 60:
                if str(dest).lower() == "hosur":
                    total_fare += 0.9 * HOSUR_COST
                elif str(dest).lower() == "vaniyambadi":
                    total_fare += 0.9 * VANIYAMBADI_COST
                elif str(dest).lower() == "vellore":
                    total_fare += 0.9 * VELLORE_COST
                elif str(dest).lower() == "walaja":
                    total_fare += 0.9 * WALAJA_COST
                elif str(dest).lower() == "chennai":
                    total_fare += 0.9 * CHENNAI_COST
                
            total_fare += addt_cost
    fare = total_fare
    if days_bween >= 20:
        return fare
    elif 14 <= days_bween < 20:
        return 0.9 * fare
    elif 7 <= days_bween < 14:
        return 0.8 * fare
    elif 4 <= days_bween < 7:
        return 0.5 * fare
    else:
        return 0    


def calc_total_fare(booking_option, dest, details):
    total_fare = 0
    addt_cost = 0
    
    if booking_option == 'B':
        addt_cost = 100
    
    for detail in details:
        if detail['age'] < 60:
            if str(dest).lower() == "hosur":
                total_fare += HOSUR_COST
            elif str(dest).lower() == "vaniyambadi":
                total_fare += VANIYAMBADI_COST
            elif str(dest).lower() == "vellore":
                total_fare += VELLORE_COST
            elif str(dest).lower() == "walaja":
                total_fare += WALAJA_COST
            elif str(dest).lower() == "chennai":
                total_fare += CHENNAI_COST
        elif detail['age'] >= 60:
            if str(dest).lower() == "hosur":
                total_fare += 0.9 * HOSUR_COST
            elif str(dest).lower() == "vaniyambadi":
                total_fare += 0.9 * VANIYAMBADI_COST
            elif str(dest).lower() == "vellore":
                total_fare += 0.9 * VELLORE_COST
            elif str(dest).lower() == "walaja":
                total_fare += 0.9 * WALAJA_COST
            elif str(dest).lower() == "chennai":
                total_fare += 0.9 * CHENNAI_COST
        
        total_fare += addt_cost

    return total_fare


if __name__ == "__main__":        
    main()