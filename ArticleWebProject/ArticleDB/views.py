from django.shortcuts import render, redirect
from .forms import ArticleForm
from .models import Article

# Create your views here.


def article_List(request):
    context = {'article_list': Article.objects.all()}
    return render(request,"ArticleDB/article_list.html" , context)


def article_Form(request , id=0):
    if request.method == "GET":
        if id == 0:
            form = ArticleForm()
        else:
            title = Article.objects.get(pk=id)
            form = ArticleForm(instance = title)
        return render(request, "ArticleDB/article_forms.html", {'form': form})
    else:
        if id == 0:
            form = ArticleForm(request.POST)
        else:
            title = Article.objects.get(pk=id)
            form = ArticleForm(request.POST,instance = title)
        if form.is_valid():
            form.save()
        return redirect('/list')


def article_Delete(request,id):
    title = Article.objects.get(pk=id)
    title.delete()
    return redirect('/list')
