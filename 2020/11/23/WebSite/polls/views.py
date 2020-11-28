from django.http import HttpRequest
from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def index(request: HttpRequest) -> HttpResponse:
    return HttpResponse("Hello! You're using the index page of polls")

def detail(request: HttpRequest) -> HttpResponse:
    return HttpResponse("This is the detail page of polls app")

def vote(request: HttpRequest) -> HttpResponse:
    return HttpResponse("This is a vote page")
