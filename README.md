# cs3520-ai-processor
Of course. This is a crucial first step. Let's craft a structured approach to your **Domain Analysis Report** for Week 5.

This report isn't about technical processor details yet. It's about proving you understand the *problem space*: the user, their needs, the applications that serve those needs, and the computational demands of those applications.

Here is a step-by-step guide and a template you can use.

### **Step-by-Step Guide to Completing Week 5's Deliverable**

**Objective:** To produce a short report (3-5 pages) that defines the context and justifies your choice of representative applications based on the needs of rural Lesotho.

**Step 1: Define the User and Their Context**
*   **Who is the user?** A smallholder farmer in a rural area of Lesotho.
*   **What are their constraints?**
    *   **Cost:** The device must be ultra-low-cost.
    *   **Connectivity:** Internet access is limited, expensive, and unreliable. Apps must work **offline**.
    *   **Power:** Access to electricity for charging may be limited. The device and its processor must be **extremely power-efficient**.
    *   **Literacy/Language:** Interfaces must be voice-driven and in local languages (e.g., Sesotho).

**Step 2: Identify Core Problem Areas**
Based on the constraints above, what are the biggest problems technology can solve?
1.  **Access to Agricultural Knowledge:** When to plant, what to plant, how to treat diseases.
2.  **Language Barriers:** Accessing digital services that are often in English.
3.  **Financial Inclusion:** Secure, low-bandwidth mobile money and identity verification.

**Step 3: Select Representative Applications**
Choose 2-3 applications that address the problems above and are feasible on a low-cost device. These will be the focus of your entire project.
*   **Your Choice:** **1. Vernacular Speech Interface** and **2. On-Device Crop Disease Detection** are perfect choices.
*   **Justification:** They directly address problems 1 and 2, are highly dependent on efficient local computation (AI inference), and have clearly defined workloads.

**Step 4: Analyze the Workload Requirements**
For each application, break down what it requires from the processor. This is the most important part.

---

### **Domain Analysis Report Template**

You can structure your report using the following template.

# **Domain Analysis Report: AI for Rural Mobile Telephony in Lesotho**

**Group Name:** [Your Group Name]
**Date:** [Date of Submission]

### **1. Introduction**

This report outlines the analysis of the mobile AI telephony context for low-cost devices in rural Lesotho. The primary goal is to identify representative applications and their associated computational workloads to inform the design of a customized, efficient RISC-V processor. The core design constraints are ultra-low cost, minimal power consumption, and offline functionality.

### **2. Target User and Context**

The primary user is a smallholder farmer in rural Lesotho. Their key characteristics relevant to this project are:
*   **Economic Reality:** Requires technology that is affordable to acquire and operate.
*   **Connectivity:** Lives in an area with limited or no reliable internet access, necessitating fully offline application functionality.
*   **Infrastructure:** Has limited access to a stable electrical grid, making device power efficiency a critical factor.
*   **Usability:** May have low literacy levels and is primarily Sesotho-speaking, requiring voice-based and vernacular language interfaces.

These constraints directly dictate the technical requirements for both the applications and the underlying processor.

### **3. Representative Applications & Workload Requirements**

Based on the user context, two representative applications have been selected for analysis.

#### **3.1. Application 1: Vernacular Speech Command & Translation**

*   **Description:** An offline application that allows users to interact with their phone and access agricultural information databases using spoken Sesotho commands. It may also provide simple translation services for key agricultural terms.
*   **Local Problem Solved:** Breaks down language and literacy barriers, providing access to digital services through the most natural interface: speech.
*   **Workload Requirements:**
    *   **Computation:** Dominated by the inference of a small, specialized Recurrent Neural Network (RNN) or a similar lightweight model for speech recognition and translation.
    *   **Key Operation:** Dense **Matrix Multiplications** (Millions of Multiply-Accumulate - MAC - operations). This is the fundamental workload for neural networks.
    *   **Memory:** Requires frequent access to a pre-loaded model (weights and biases). Memory bandwidth and efficient caching are important to keep the processor fed with data.
    *   **Precision:** To save cost and power, **fixed-point arithmetic** (16-bit or 8-bit) is preferred over more expensive floating-point (32-bit).

#### **3.2. Application 2: On-Device Crop Disease Detection**

*   **Description:** An offline application that uses the phone's camera to capture an image of a plant leaf and uses a lightweight Convolutional Neural Network (CNN) to identify signs of common diseases specific to crops in Lesotho (e.g., maize, sorghum).
*   **Local Problem Solved:** Provides immediate, actionable agricultural advice without the need for an internet connection or a visit from an extension officer, potentially saving harvests.
*   **Workload Requirements:**
    *   **Computation:** Dominated by the **Convolutional layers** of a CNN. Convolution involves sliding a small filter across an image, which is mathematically equivalent to a vast number of MAC operations.
    *   **Key Operation:** Massively parallel **Multiply-Accumulate (MAC)** operations. The same operation is applied independently across the entire image, indicating high potential for data parallelism.
    *   **Memory:** Has high memory bandwidth demands due to the need to access image pixel data and filter weights simultaneously. A focus on efficient data movement is critical.
    *   **Precision:** **Fixed-point arithmetic** (16-bit or 8-bit) is again sufficient for image classification, keeping hardware costs low.

### **4. Summary of Common Workload Characteristics**

The analysis of the two representative applications reveals a common set of processor workload requirements:

1.  **Compute-Centric:** Both workloads are dominated by **Multiply-Accumulate (MAC)** operations.
2.  **Memory-Intensive:** Both require efficient handling of model weights and input data (audio features, images).
3.  **Suitable for Parallelism:** The image processing workload, in particular, is highly data-parallel.
4.  **Precision:** **Fixed-point arithmetic** is a viable and cost-effective solution for both applications.

These shared characteristics will directly guide the customization of the RISC-V ISA and the design of the microarchitecture in the subsequent phases of this project, ensuring the final processor is tailored for efficiency and low cost.

---
This report provides the "why" behind your technical decisions. Once you have this document drafted, you are perfectly set up to start writing the C++ prototype programs that embody these workloads.

**Shall we now look at how to write those C++ prototype programs for the Vernacular Speech and Crop Disease applications?**