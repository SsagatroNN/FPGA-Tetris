import flask as Flask
from flask import request




app = Flask.Flask(__name__)



@app.route("/data")
def data():
	print(request.url_root)
	return "shit"



app.run()



