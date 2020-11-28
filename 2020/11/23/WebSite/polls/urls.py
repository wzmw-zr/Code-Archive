#!/usr/bin/env python
# coding=utf-8
from django.urls import path
from . import views

urlpatterns = [
    path("index", views.index, name = "index"),
    path("detail", views.detail, name = "detail"),
    path("vote", views.vote, name = "vote")
]
