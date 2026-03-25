# Graph Projects

基于 [LangGraph](https://github.com/langchain-ai/langgraph) 构建的多步骤 AI Agent，使用通义千问 (Qwen) 作为底层大模型。

## 架构

```
用户输入
  │
  ▼
decide_agent_type (路由：chat / rag / image)
  │
  ▼
orchestrator_node (任务拆解)
  │
  ▼
collect_tasks_node (任务优化压缩)
  │
  ▼
┌─ llm_node ─── tool_node ──┐
│         (循环)             │
└────────────────────────────┘
  │
  ▼
worker_node (执行任务并汇总结果)
  │
  ▼
输出最终结果
```

## 功能

- **任务规划**：将用户请求自动拆解为可执行的步骤列表
- **工具调用**：支持 DuckDuckGo 搜索、网页抓取、获取当前时间
- **对话记忆**：维护多轮对话的 chat_history，历史过长时自动压缩摘要
- **流式输出**：实时展示每个节点的执行进度

## 项目结构

```
xs_graph_project/
├── demo1/
│   ├── frame.ipynb      # 主 Agent 实现（LangGraph 流程图）
│   └── pdf-md.ipynb     # PDF 转 Markdown 实验
└── test/
    └── main.cpp         # C++ 算法模板
```

## 环境配置

1. 安装依赖：
```bash
pip install -r requirements.txt
```

2. 配置环境变量：
```bash
cp .env.example .env
# 编辑 .env，填入你的 DASHSCOPE_API_KEY
```

3. 运行 notebook：
```bash
jupyter notebook xs_graph_project/demo1/frame.ipynb
```

## 使用的模型

- **LLM**: Qwen-Turbo (通义千问)
- **API**: 阿里云 DashScope OpenAI 兼容接口

## License

MIT
