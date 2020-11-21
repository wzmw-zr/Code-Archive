from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def index(request):
    return HttpResponse("Hello, world.You're at the polls index")

def detail(request, question_id):
    return HttpResponse(f"You're looking at question {question_id}")

def results(request, question_id):
    return HttpResponse(f"You're looking at results of {question_id}")

def vote(request, question_id):
    return HttpResponse(f"You're voting on a question {question_id}")
