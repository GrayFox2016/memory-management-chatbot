#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // 由于存在用户定义的析构方法（destructor）、复制构造（copy-constructor）、赋值运算符重载（copy-assignment operator）阻止了隐式定义的移动构造（move constructor）和移动赋值运算符（move assignment operator），任何想要设计为允许移动语义的类，都必须声明以下所有五个特殊的成员方法：

    // copy-constructor
    ChatBot(const ChatBot &src); 
    // copy-assignment operator
    ChatBot& operator=(const ChatBot &src); 
    // move constructor
    ChatBot(ChatBot &&src);
    // move assignment operator
    ChatBot& operator=(ChatBot &&src);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */