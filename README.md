# 🎓 My E-Portfolio

A clean, fast static e-portfolio site built with plain HTML/CSS/JS — no frameworks, no build tools needed. Just open a file and edit.

**Live site:** `https://yourusername.github.io/eportfolio` *(replace after deploying)*

---

## 🚀 How to Deploy on GitHub Pages (step by step)

### 1. Create a GitHub repository
1. Go to [github.com](https://github.com) and sign in
2. Click the **+** button → **New repository**
3. Name it `eportfolio` (or anything you like)
4. Set it to **Public**
5. Click **Create repository**

### 2. Upload your files
**Option A — via the GitHub website (easiest):**
1. Open your new repository
2. Click **Add file** → **Upload files**
3. Drag in the entire `eportfolio/` folder (or just `index.html` + the `assets/` folder)
4. Click **Commit changes**

**Option B — via Git on your computer:**
```bash
cd eportfolio
git init
git add .
git commit -m "Initial portfolio"
git remote add origin https://github.com/yourusername/eportfolio.git
git push -u origin main
```

### 3. Enable GitHub Pages
1. In your repository, go to **Settings** → **Pages** (left sidebar)
2. Under **Source**, select **Deploy from a branch**
3. Choose branch: `main`, folder: `/ (root)`
4. Click **Save**

### 4. Get your link
Wait ~1 minute, then your site is live at:
```
https://yourusername.github.io/eportfolio
```
Share this link with anyone!

---

## ✏️ How to Edit Your Portfolio

Everything is in **one file: `index.html`**. Scroll down to the big `<script>` block — you'll see clearly labeled sections:

### Update your personal info
```js
const PROFILE = {
  name:    "Your Full Name",       // ← change this
  tagline: "Your tagline here",    // ← change this
  bio:     "A short paragraph...", // ← change this
  links: [
    { label: "GitHub", url: "https://github.com/YOU", type: "outline" },
    { label: "Email Me", url: "mailto:you@email.com",  type: "primary" },
  ],
};
```

### Add a new project
Find the right year in `const YEARS = [...]` and add a new object inside `projects: [...]`:

```js
{
  title:       "My New Project",
  image:       "assets/images/my-project.png",  // or "" for placeholder
  description: "What the project does and what you learned.",
  tags:        ["Python", "Flask", "SQL"],
  type:        "Web App",
  reportUrl:   "https://github.com/yourusername/my-project",
},
```

### Add a project preview image
1. Put your image in the `assets/images/` folder
2. Set `image: "assets/images/your-image.png"` in the project object
3. Recommended size: **800 × 500 px** (16:10 ratio looks best)

### Upload your report PDF
1. Create an `assets/reports/` folder in your repo
2. Upload your PDF there (e.g. `assets/reports/year1-library.pdf`)
3. Set `reportUrl: "assets/reports/year1-library.pdf"` in the project object

---

## 📁 Folder Structure

```
eportfolio/
├── index.html          ← The entire site (edit this)
├── README.md           ← This file
└── assets/
    ├── images/         ← Project preview screenshots
    │   └── my-project.png
    └── reports/        ← PDF reports (optional)
        └── year1-project.pdf
```

---

## 🔄 Updating after changes

After editing `index.html` on GitHub (via the pencil edit button in the web UI), the site updates automatically within about 30 seconds.

If using Git locally:
```bash
git add .
git commit -m "Add Year 2 project: attendance app"
git push
```

---

## 💡 Tips

- **Report links** can point to a GitHub repo, a PDF in `assets/reports/`, or a Google Drive link — whatever you prefer
- **Tags** are just labels — put whatever tech or topic is relevant
- **Images** are optional — a placeholder shows if you leave `image: ""`
- **Skills** in the About section are easy to update in `const ABOUT_BLOCKS`
