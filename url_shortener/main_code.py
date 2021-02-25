import bitly_api

Access_token = "" # hidden

connection= bitly_api.Connection(access_token = Access_token)

url = input()

shorten_url = connection.shorten(url);

print(shorten_url.get('url'))
