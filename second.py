#!/usr/bin/env python3.6
from flask import Flask, render_template, request, escape

app = Flask(__name__)

@app.route('/')
@app.route('/start')
def upload() -> 'html':
    return render_template('entry.html', the_title = 'JSON Search Engine HTTP API') 

@app.route('/search', methods = ['POST'])
def search() -> 'html':
    directory = request.form['dir']
    field = request.form['field']
    value = request.form['value']

    print(field)

    return render_template('result.html', the_title = 'Result', the_dir = directory, the_field = field, the_value = value)

if __name__ == '__main__':
    app.run(debug=True, port = 8080)
