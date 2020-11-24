from django.urls import path
from . import views

urlpatterns = [
    path("add/", views.add_worker, name = "add_worker"),
    path("select/", views.select_worker, name = "select_worker"),
    path("modify/", views.modify_worker, name = "modify_worker")
]