for _ in range(int(input())):
    sent = input()
    if sent[-1] == 'o':
        print("FILIPINO")
    else:
        print("JAPANESE" if sent[-1] == 'u' else "KOREAN")
