from django.http import HttpRequest
from django.http import HttpResponse
from django.shortcuts import render
from .models import Question
from .models import Choice

# Create your views here.
def index(request: HttpRequest) -> HttpResponse:
    latest_question_list = Question.objects.order_by('-pub_date')[:5]
    output = ",".join([q.question_text for q in latest_question_list])
    return HttpResponse(output)

def detail(request: HttpRequest, question_id: str) -> HttpResponse:
    return HttpResponse(f"You're looking at question {question_id}")

def results(request: HttpRequest, question_id: str) -> HttpResponse:
    return HttpResponse(f"You're looking at the results of question {question_id}")

def vote(request: HttpRequest, question_id: str) -> HttpResponse:
    return HttpResponse(f"You're voting on question {question_id}")
