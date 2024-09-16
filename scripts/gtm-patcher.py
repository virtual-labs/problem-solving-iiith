#!/usr/bin/python

from bs4 import BeautifulSoup, Tag, Comment
import sys

headSnippet = """(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','dataLayer','GTM-W59SWTR');"""

iframeSrc = "https://www.googletagmanager.com/ns.html?id=GTM-W59SWTR"


insert_head = "<script class='gtm'>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src='https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);})(window,document,'script','dataLayer','GTM-W59SWTR');</script>"
def patch_php(filepath):
    # print(filepath)
    try:
        if(1):
            f1 = open(filepath,"r")
            lines = f1.readlines()
            string_inserted = ''
            for line in lines:
                if("<script class='gtm'>" in line):
                    return
            f1.close()
        if(1):
            # print(filepath)
            f1 = open(filepath,"r")
            lines = f1.readlines()
            # print(lines)
            string_inserted = ''
            for line in lines:
                if('<head>' in line):
                    line = line.split('<head>')
                    temp_string = line[0]
                    temp_string+='<head>\n'
                    temp_string+=insert_head+'\n'
                    for i in line[1:]:
                        temp_string+=i
                    line = temp_string
                string_inserted+=line
            print(string_inserted)
            f1.close()
            f = open(filepath,"w")
            f.write(string_inserted)
            f.close()

    except IOError as e:
        print "I/O error({0}): {1}".format(e.errno, e.strerror)
        return -1
    except:
        print "Unexpected error:", sys.exc_info()[0]
        return -2
    print "Analytics Patched Successfully"
    return 0

# load the file
def patch(filepath):
    if("php" in filepath):
        patch_php(filepath)
        return 0
    try:
        with open(filepath) as inf:
            txt = inf.read()
            # soup = BeautifulSoup(txt, 'html.parser')
            soup = BeautifulSoup(txt, "html5lib")
        mydiv = soup.head.find('script', { 'class': 'gtm' })
        if not mydiv:
            scrTag = Tag(soup, name = 'script')
            scrTag['class'] = "gtm"
            scrTag.string = headSnippet
            soup.head.insert(0, Comment('End Google Tag Manager'))
            soup.head.insert(0, scrTag)
            soup.head.insert(0, Comment('Google Tag Manager'))
            #scrTag.insert_before(Comment('Google Tag Manager'))
            #scrTag.insert_after(Comment('End Google Tag Manager'))

            # insert body snippet into the document
            iframeTag = Tag(soup, name = 'iframe')
            iframeTag['src'] = iframeSrc
            iframeTag['height'] = "0"
            iframeTag['width'] = "0"
            iframeTag['style'] = "display:none;visibility:hidden"

            noscrTag = Tag(soup, name = 'noscript')
            noscrTag['class'] = 'gtm'
            noscrTag.insert(0, iframeTag)
            soup.body.insert(0, Comment('End Google Tag Manager (noscript)'))
            soup.body.insert(0, noscrTag)
            soup.body.insert(0, Comment('Google Tag Manager (noscript)'))
            #noscrTag.insert_before(Comment('Google Tag Manager (noscript)'))
            #noscrTag.insert_after(Comment('End Google Tag Manager (noscript)'))

        # save the file again
        with open(filepath, 'w') as outf:
            outf.write(str(soup))

    except IOError as e:
        print "I/O error({0}): {1}".format(e.errno, e.strerror)
        return -1
    except:
        print "Unexpected error:", sys.exc_info()[0]
        return -2
    print "Analytics Patched Successfully " + filepath
    return 0


if __name__=='__main__':
    patch(sys.argv[1])
