from cryptography.fernet import Fernet

key = b'GuEhxHXE-zS3UZi1Dqr8EOt0fvaDRrZCazVXrAK5rcA='
f = Fernet(key)

input_string = input("' haki '")

print('\n')

substrings = input_string.split(' haki ')

for substring in substrings:
    text = bytes(substring, 'utf-8')
    decrypted_data = f.decrypt(text)
    print(decrypted_data.decode())
