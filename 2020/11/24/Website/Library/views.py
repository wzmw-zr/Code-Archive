from django.http import HttpRequest
from django.http import HttpResponse
from django.shortcuts import render
from datetime import datetime
import json
from . import models

# Create your views here.
def add_worker(request: HttpRequest) -> HttpResponse:
    models.Worker.objects.create(Name = "Lao Wang")
    return HttpResponse("You add a worker")

def select_worker(request: HttpRequest) -> HttpResponse:
    ans = models.Worker.objects.filter(Name = "Lao Wang")
    print(type(ans))
    print(type(ans.values()))
    temp_list = [dict(item) for item in ans.values()]
    print(temp_list)
    return HttpResponse("Lao Wang")

def modify_worker(request: HttpRequest) -> HttpResponse:
    models.Worker.objects.filter(Name = "Lao Wang").update(Name = "Lao Li")
    return HttpResponse("You successfully chang a worker's information")
