import bitly_api

Access_token = "548bf7c66df07ba9054d9df5d1f50ee1f7a950be"

connection= bitly_api.Connection(access_token = Access_token)

url = input()

shorten_url = connection.shorten(url);

print(shorten_url.get('url'))
