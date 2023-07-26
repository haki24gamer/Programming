from cryptography.fernet import Fernet

key = b'GuEhxHXE-zS3UZi1Dqr8EOt0fvaDRrZCazVXrAK5rcA='
f = Fernet(key)


text = input()
text = bytes(text, 'utf-8')

encrypted = f.encrypt(text)
print(encrypted.decode())