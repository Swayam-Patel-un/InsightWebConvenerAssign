from django.urls import path , include
from . import views

urlpatterns = [
    path('', views.article_Form,name='article_insert'), 
    path('<int:id>/', views.article_Form,name='article_update'), 
    path('delete/<int:id>/',views.article_Delete,name='article_delete'),
    path('list/',views.article_List,name='article_list') 
]