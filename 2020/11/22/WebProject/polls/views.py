from django.http import HttpRequest
from django.http import HttpResponse
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.shortcuts import get_object_or_404
from django.template import loader
from django.urls import reverse
from .models import Question
from .models import Choice

# Create your views here.
def index(request: HttpRequest) -> HttpResponse:
    return render(request, "polls/index.html")

def detail(request: HttpRequest, question_id: str) -> HttpResponse:
    question = get_object_or_404(Question, pk = question_id)
    return render(request, "polls/detail.html", {"question" : question})

def results(request: HttpRequest, question_id: str) -> HttpResponse:
    return HttpResponse(f"You're looking at the results of question {question_id}")

def vote(request, question_id):
    question = get_object_or_404(Question, pk=question_id)
    try:
        selected_choice = question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        # Redisplay the question voting form.
        return render(request, 'polls/detail.html', {
            'question': question,
            'error_message': "You didn't select a choice.",
        })
    else:
        selected_choice.votes += 1
        selected_choice.save()
        # Always return an HttpResponseRedirect after successfully dealing
        # with POST data. This prevents data from being posted twice if a
        # user hits the Back button.
        return HttpResponseRedirect(reverse('polls:results', args=(question.id,)))
